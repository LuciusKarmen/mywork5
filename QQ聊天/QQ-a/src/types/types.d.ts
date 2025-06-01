export interface ChatMessage {
  id?: number
  sender: string
  recipient: string
  content: string
  timestamp?: string | Date
  seen?: boolean
}

export interface ChatMessageDTO {
  sender: string
  recipient: string
  content: string
}
