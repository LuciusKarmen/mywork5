<template>
  <div class="message-list">
    <div 
      v-for="(message, index) in messages" 
      :key="index" 
      :class="['message', { 'my-message': message.sender === currentUser }]"
    >
      <div class="message-content">{{ message.content }}</div>
      <div class="message-time">{{ formatTime(message.timestamp) }}</div>
    </div>
  </div>
</template>

<script setup lang="ts">
defineProps<{
  messages: Array<{
    content: string;
    sender: string;
    recipient: string;
    timestamp?: Date;
  }>;
  currentUser: string;
}>();

const formatTime = (timestamp: Date | undefined): string => {
  if (!timestamp) return '';
  return new Date(timestamp).toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' });
};
</script>