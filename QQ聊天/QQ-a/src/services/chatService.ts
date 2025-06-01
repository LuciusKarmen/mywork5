import axios from 'axios'
import type { ChatMessageDTO } from '../types/types'

const apiClient = axios.create({
  baseURL: 'http://localhost:8080/api/messages',
})

// 获取两个用户之间的消息
export const getMessages = async (user1: string, user2: string) => {
  const res = await apiClient.get('', {
    params: { user1, user2 },
  })
  return res.data
}

// 发送消息
export const sendMessage = async (message: ChatMessageDTO) => {
  const res = await apiClient.post('', message)
  return res.data
}
