<template>
  <div id="app">
    <h1>QQ 聊天系统</h1>
    <ChatWindow :current-user="currentUser" />
  </div>
</template>

<script setup lang="ts">
import ChatWindow from './components/ChatWindow.vue'
import { ref } from 'vue'

const currentUser = ref('testUser')
</script>
