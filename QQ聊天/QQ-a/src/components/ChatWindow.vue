<script setup lang="ts" name="ChatWindow">
import { ref, onMounted } from 'vue'
import MessageList from './MessageList.vue'
import ContactList from './ContactList.vue'
import { getMessages as fetchMessages, sendMessage as sendApiMessage } from '@/services/chatService'
import type { ChatMessage, ChatMessageDTO } from '../types/types'

const props = defineProps<{
  currentUser: string
}>()

const contacts = ref(['Alice', 'Bob', 'Charlie'])
const selectedContact = ref<string | null>(null)
const messages = ref<ChatMessage[]>([])
const newMessageContent = ref('')

const selectContact = async (contact: string) => {
  selectedContact.value = contact
  messages.value = await fetchMessages(props.currentUser, contact)
}

const sendMessage = async () => {
  if (!selectedContact.value || !newMessageContent.value) return

  const message: ChatMessageDTO = {
    sender: props.currentUser,
    recipient: selectedContact.value,
    content: newMessageContent.value,
  }

  // 发送到后端
  await sendApiMessage(message)

  // 添加到本地显示
  messages.value.push({
    ...message,
    timestamp: new Date().toISOString(),
    seen: false,
  })

  newMessageContent.value = ''
}

// 连接 WebSocket 实时接收消息
onMounted(() => {
  const ws = new WebSocket(`ws://localhost:8080/ws/${props.currentUser}`)

  ws.onmessage = (event) => {
    try {
      const receivedMessage = JSON.parse(event.data)
      if (
        receivedMessage.sender === selectedContact.value ||
        receivedMessage.recipient === selectedContact.value
      ) {
        messages.value.push(receivedMessage)
      }
    } catch (error) {
      console.error('Error parsing message:', error)
    }
  }
})
</script>

<template>
  <div class="chat-container">
    <div class="contacts">
      <ContactList :contacts="contacts" @select-contact="selectContact" />
    </div>
    <div class="chat-box">
      <MessageList :messages="messages" :current-user="currentUser" />
      <form class="send-form" @submit.prevent="sendMessage">
        <input v-model="newMessageContent" placeholder="输入消息..." required />
        <button type="submit">发送</button>
      </form>
    </div>
  </div>
</template>

<style scoped>
.chat-container {
  display: flex;
  height: 100vh;
}

.contacts {
  width: 25%;
  border-right: 1px solid #ccc;
  padding: 10px;
}

.chat-box {
  flex: 1;
  display: flex;
  flex-direction: column;
  padding: 10px;
}

.send-form {
  margin-top: auto;
  display: flex;
  gap: 10px;
}

input {
  flex: 1;
  padding: 10px;
}

button {
  padding: 10px 20px;
}
</style>
