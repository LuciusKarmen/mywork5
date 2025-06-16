<template>
  <div id="app">
    <h1>星辰推球小游戏</h1>
    <SandBallGame />
  </div>
</template>

<script setup lang="ts" name="App">
import SandBallGame from './components/SandBallGame.vue'
</script>

<style scoped lang="scss">

#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  text-align: center;
  color: #2c3e50;
  margin-top: 20px;
}
@use './index.css'
</style>