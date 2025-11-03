<template>
  <div id="ChinaMap" class="map-container"></div>
</template>

<script lang="ts" setup name="ChinaPopulationMap">
import { ref, onMounted, onUnmounted } from 'vue'
import * as echarts from 'echarts'
import type { EChartsOption } from 'echarts' // 引入类型定义，获得更好的类型提示

// 👉 1. 定义图表实例引用
const map = ref<echarts.ECharts | null>(null)

// 👉 2. 定义 resize 回调函数 (具名函数，用于正确移除监听器)
const handleResize = () => {
  map.value?.resize()
}

// 👉 3. 中国各省份人口数据 (示例数据，单位：万人，基于第七次人口普查近似值)
// 实际项目中，建议从 API 接口动态获取最新数据
const chinaPopulationData = [
  { name: '北京', value: 2189.3 },
  { name: '天津', value: 1386.6 },
  { name: '河北', value: 7461.0 },
  { name: '山西', value: 3491.6 },
  { name: '内蒙古', value: 2404.9 },
  { name: '辽宁', value: 4259.1 },
  { name: '吉林', value: 2407.3 },
  { name: '黑龙江', value: 3185.0 },
  { name: '上海', value: 2487.1 },
  { name: '江苏', value: 8474.8 },
  { name: '浙江', value: 6456.8 },
  { name: '安徽', value: 6102.7 },
  { name: '福建', value: 4154.0 },
  { name: '江西', value: 4518.9 },
  { name: '山东', value: 10152.7 },
  { name: '河南', value: 9936.6 },
  { name: '湖北', value: 5775.3 },
  { name: '湖南', value: 6644.5 },
  { name: '广东', value: 12601.3 },
  { name: '广西', value: 5012.7 },
  { name: '海南', value: 1008.1 },
  { name: '重庆', value: 3205.4 },
  { name: '四川', value: 8367.5 },
  { name: '贵州', value: 3856.2 },
  { name: '云南', value: 4720.9 },
  { name: '西藏', value: 364.8 },
  { name: '陕西', value: 3952.9 },
  { name: '甘肃', value: 2501.9 },
  { name: '青海', value: 592.4 },
  { name: '宁夏', value: 720.4 },
  { name: '新疆', value: 2585.2 },
  // 注意：台湾、香港、澳门的数据在此示例中省略。
]

// 👉 4. 图表配置选项 (使用 EChartsOption 类型)
const option: EChartsOption = {
  title: {
    text: '中国人口分布热力图 (2020年)',
    subtext: '数据来源：第七次全国人口普查 (示例数据)',
    left: 'center',
    textStyle: {
      fontSize: 18,
      fontWeight: 'bold',
    },
  },
  tooltip: {
    trigger: 'item',
    formatter: (params) => {
      return `${params.name}<br/>人口: ${params.value} 万人`
    },
    backgroundColor: 'rgba(50, 50, 50, 0.8)',
    borderColor: '#333',
    borderWidth: 1,
    textStyle: {
      color: '#fff',
    },
  },
  // 👉 5. visualMap 是实现热力图的关键
  visualMap: {
    min: 300, // 最小人口值 (万人)
    max: 13000, // 最大人口值 (万人)
    left: 'right',
    top: 'middle',
    text: ['人口多', '人口少'], // 图例文字
    calculable: true, // 显示拖拽手柄
    inRange: {
      // 定义颜色渐变，数值越大颜色越深
      color: ['#f0f9e8', '#bae4bc', '#7bccc4', '#43a2ca', '#0868ac'],
      // 也可以用 ['#c6dbef', '#9ecae1', '#6baed6', '#4292c6', '#2171b5']
    },
    // orient: 'vertical', // 垂直
    // 如果想放在底部
    // top: 'bottom',
    // left: 'center'
  },
  toolbox: {
    show: true,
    feature: {
      dataView: { readOnly: false },
      restore: {},
      saveAsImage: {},
    },
  },
  series: [
    {
      name: '人口 (万人)',
      type: 'map', // 系列类型为地图
      map: 'china', // 使用注册的地图名称
      roam: true, // 开启缩放和平移
      emphasis: {
        label: {
          show: true,
          fontSize: 14,
          fontWeight: 'bold',
        },
        itemStyle: {
          areaColor: '#a5d8ff', // 高亮时的颜色
        },
      },
      data: chinaPopulationData, // 绑定人口数据
    },
  ],
}

onMounted(async () => {
  // 👉 6. 获取图表 DOM 元素
  const chartDom = document.getElementById('ChinaMap')
  if (!chartDom) {
    console.error('Chart container not found!')
    return
  }

  // 👉 7. 初始化 ECharts 实例
  map.value = echarts.init(chartDom)

  try {
    // 👉 8. 异步加载中国地图 GeoJSON 数据
    // 这里使用 jsDelivr 托管的 ECharts 官方数据
    const response = await fetch('https://echarts.apache.org/examples/data/asset/geo/china.json')
    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`)
    }
    const chinaJson = await response.json()

    // 👉 9. 注册地图
    echarts.registerMap('china', chinaJson)

    // 👉 10. 设置图表配置
    map.value.setOption(option)
  } catch (error) {
    console.error('Failed to load map data:', error)
    // 设置一个错误提示
    map.value.setOption({
      title: { text: '地图数据加载失败' },
      graphic: {
        elements: [
          {
            type: 'text',
            z: 100,
            left: 'center',
            top: 'middle',
            style: {
              text:
                '地图数据加载失败\n' + (error instanceof Error ? error.message : 'Unknown error'),
              fill: '#333',
              font: '16px Microsoft YaHei',
              textAlign: 'center',
            },
          },
        ],
      },
    })
  }

  // 👉 11. 添加窗口 resize 事件监听
  window.addEventListener('resize', handleResize)
})

onUnmounted(() => {
  // 👉 12. 清理工作
  if (map.value) {
    // 移除 resize 监听器 (使用同一个函数引用)
    window.removeEventListener('resize', handleResize)
    // 销毁图表实例
    map.value.dispose()
    map.value = null
  }
})
</script>

<style lang="scss" scoped>
// 👉 13. 样式：确保容器有足够大小
.map-container {
  width: 100%;
  height: 800px; // 可以根据需要调整
  // 可选：添加边框、阴影或背景
  border: 1px solid #ddd;
  border-radius: 8px;
  box-shadow: 0 2px 12px rgba(0, 0, 0, 0.1);
  // 防止内容溢出
  overflow: hidden;
}

// 响应式设计 (可选)
@media (max-width: 768px) {
  .map-container {
    height: 600px;
  }
}
</style>
