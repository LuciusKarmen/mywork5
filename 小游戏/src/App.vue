<template>
  <div id="app">
    <h1>星辰推球小游戏</h1>
    <SandBallGame />
  </div>
</template>

<script setup lang="ts" name="App">
import SandBallGame from '../src/components/SandBallGame.vue';
</script>

<style scoped lang="scss">
@use './index.css' as *;
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  text-align: center;
  color: #2c3e50;
  margin-top: 20px;
}

</style>