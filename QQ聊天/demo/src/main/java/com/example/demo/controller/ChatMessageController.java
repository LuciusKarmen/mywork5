package com.example.demo.controller;

import com.example.demo.model.ChatMessage;
import com.example.demo.service.ChatMessageService;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/api/messages")
public class ChatMessageController {

    private final ChatMessageService chatMessageService;

    public ChatMessageController(ChatMessageService chatMessageService) {
        this.chatMessageService = chatMessageService;
    }

    // 获取两个用户之间的消息
    @GetMapping
    public List<ChatMessage> getMessages(@RequestParam String user1, @RequestParam String user2) {
        return chatMessageService.getMessages(user1, user2);
    }

    // 发送消息
    @PostMapping
    public void sendMessage(@RequestBody ChatMessage message) {
        chatMessageService.saveMessage(message);
    }
}