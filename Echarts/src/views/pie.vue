<template>
  <div id="a" class="pie"></div>
</template>
<script lang="ts" setup name="">
import { ref, onMounted, onUnmounted } from 'vue'
import * as echarts from 'echarts'
let myChart = ref<echarts.ECharts | null>(null)
onMounted(() => {
  myChart.value = echarts.init(document.getElementById('a') as HTMLElement)
  ;(myChart.value.setOption({
    title: {
      text: '饼图',
    },
    series: [
      {
        type: 'pie',
        data: [
          { value: 10, name: 'A' },
          { value: 20, name: 'B' },
          { value: 30, name: 'C' },
          { value: 40, name: 'D' },
          { value: 50, name: 'E' },
        ],
      },
    ],
  }),
    window.addEventListener('resize', () => {
      myChart.value?.resize()
    }))
})
onUnmounted(() => {
  if (myChart.value) {
    // 移除 resize 监听器（如果添加了）
    window.removeEventListener('resize', () => myChart.value?.resize())
    // 销毁图表实例
    myChart.value.dispose()
    myChart.value = null
  }
})
</script>
<style lang="scss" scoped>
.pie {
  width: 400px;
  height: 400px;
}
</style>
