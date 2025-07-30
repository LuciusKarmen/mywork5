<template>
  <div id="main" class="chart"></div>
</template>

<script setup lang="ts">
import * as echarts from 'echarts'
import { onMounted } from 'vue'

let myChart: echarts.ECharts | null = null

onMounted(() => {
  // 此时 DOM 已经渲染完成，可以安全获取元素
  const chartDom = document.getElementById('main')
  if (!chartDom) {
    console.error('Chart container not found!')
    return
  }

  // 初始化 ECharts 实例
  myChart = echarts.init(chartDom)

  // 设置图表配置项
  myChart.setOption({
    title: {
      text: 'ECharts 入门示例',
    },
    tooltip: {},
    xAxis: {
      data: ['衬衫', '羊毛衫', '雪纺衫', '裤子', '高跟鞋', '袜子'],
    },
    yAxis: {},
    series: [
      {
        name: '销量',
        type: 'bar',
        data: [5, 20, 36, 1, 10, 20],
      },
    ],
  })

  // 可选：添加窗口大小变化时的图表自适应
  window.addEventListener('resize', () => {
    myChart?.resize()
  })
})

// 可选：在组件卸载前清理资源
// 注意：onUnmounted 在 script setup 中使用
import { onUnmounted } from 'vue'
onUnmounted(() => {
  if (myChart) {
    // 移除 resize 监听器（如果添加了）
    window.removeEventListener('resize', () => myChart?.resize())
    // 销毁图表实例
    myChart.dispose()
    myChart = null
  }
})
</script>

<style lang="scss" scoped>
.chart {
  width: 100%;
  height: 400px;
}
</style>
