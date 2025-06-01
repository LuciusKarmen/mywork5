<script setup lang="ts" name="MessageList">
defineProps<{
  messages: Array<{
    content: string
    sender: string
    recipient: string
    timestamp?: string
  }>
  currentUser: string
}>()

const formatTime = (timestamp: string | undefined): string => {
  if (!timestamp) return ''
  return new Date(timestamp).toLocaleTimeString([], {
    hour: '2-digit',
    minute: '2-digit',
  })
}
</script>

<template>
  <div class="message-list">
    <div
      v-for="(msg, idx) in messages"
      :key="idx"
      :class="['message', { 'my-message': msg.sender === currentUser }]"
    >
      <div class="content">{{ msg.content }}</div>
      <div class="time">{{ formatTime(msg.timestamp) }}</div>
    </div>
  </div>
</template>

<style scoped>
.message-list {
  flex: 1;
  overflow-y: auto;
  padding: 10px;
}

.message {
  margin-bottom: 10px;
  max-width: 60%;
  padding: 10px;
  border-radius: 8px;
  background-color: #eee;
}

.my-message {
  align-self: flex-end;
  background-color: #a1e8bf;
}
</style>
