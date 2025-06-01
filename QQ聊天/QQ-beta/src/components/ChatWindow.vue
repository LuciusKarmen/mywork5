<template>
  <div class="chat-window">
    <div class="contact-list">
      <ContactList :contacts="contacts" @select-contact="selectContact" />
    </div>
    
    <div class="message-container">
      <MessageList :messages="messages" :current-user="currentUser" />
      
      <form class="message-form" @submit.prevent="sendMessage">
        <input 
          v-model="newMessageContent" 
          type="text" 
          placeholder="输入消息..."
          required
        />
        <button type="submit">发送</button>
      </form>
    </div>
  </div>
</template>

<script setup lang="ts">
import { ref, onMounted } from 'vue';
import { getMessages as fetchMessages, sendMessage as sendApiMessage } from '@/services/chatService';
import MessageList from './MessageList.vue';
import ContactList from './ContactList.vue';

interface Message {
  id?: number;
  content: string;
  sender: string;
  recipient: string;
  timestamp?: Date;
  seen?: boolean;
}

const props = defineProps<{
  currentUser: string;
}>();

const contacts = ref(['user1', 'user2', 'user3']);
const selectedContact = ref<string | null>(null);
const messages = ref<Message[]>([]);
const newMessageContent = ref('');

const selectContact = async (contact: string) => {
  selectedContact.value = contact;
  // 获取历史消息
  messages.value = await fetchMessages(props.currentUser, contact);
};

const sendMessage = async () => {
  if (!selectedContact.value) return;
  
  // 发送消息
  await sendApiMessage(props.currentUser, selectedContact.value, newMessageContent.value);
  
  // 将消息添加到本地列表
  messages.value.push({
    content: newMessageContent.value,
    sender: props.currentUser,
    recipient: selectedContact.value,
    timestamp: new Date()
  });
  
  newMessageContent.value = '';
};

onMounted(() => {
  // 连接WebSocket
  const ws = new WebSocket(`ws://localhost:8080/ws/${props.currentUser}`);
  
  ws.onmessage = (event) => {
    const message = JSON.parse(event.data);
    if (message.sender === selectedContact.value || message.recipient === selectedContact.value) {
      messages.value.push(message);
    }
  };
});
</script>