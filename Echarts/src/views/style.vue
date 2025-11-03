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
  myChart = echarts.init(chartDom, 'dark')

  // 设置图表配置项
  myChart.setOption({
    title: {
      text: 'ECharts 入门示例',
    },
    tooltip: {},
    xAxis: {
      data: ['A', 'B', 'C', 'D', 'E'],
    },
    yAxis: {},
    legend: {
      show: true,
      data: ['系列1', '系列2'],
      orient: 'horizontal', // 水平布局
      left: 'center', // 水平居中
      top: 'top', // 放置在顶部
      selected: {
        系列1: true, // 系列1默认选中（可见）
        系列2: false, // 系列2默认未选中（不可见）
      },
    },
    series: [
      {
        type: 'bar',
        data: [
          10,
          22,
          28,
          {
            value: 43,
            // 设置单个柱子的样式
            itemStyle: {
              color: '#91cc75',
              shadowColor: '#91cc75',
              borderType: 'dashed',
              opacity: 0.5,
            },
          },
          49,
        ],
        itemStyle: {
          barBorderRadius: 5,
          borderWidth: 1,
          borderType: 'solid',
          borderColor: '#73c0de',
          shadowColor: '#5470c6',
          shadowBlur: 3,
        },
      },
      {
        type: 'bar',
        data: [10, 20, 30, 40, 50],
        itemStyle: {
          barBorderRadius: 5,
          borderWidth: 1,
          borderType: 'solid',
          borderColor: '#73c0de',
          shadowColor: '#5470c6',
          shadowBlur: 3,
        },
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
