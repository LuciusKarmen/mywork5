<script setup lang="ts">
import ChatWindow from '../src/components/ChatWindow.vue'
</script>

<template>
  <div id="app">
    <h1>💬 简易聊天系统</h1>
    <ChatWindow current-user="UserA" />
  </div>
</template>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  text-align: center;
  padding: 20px;
}
</style>
