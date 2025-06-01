package com.example.demo.service;



import com.example.demo.mapper.ChatMessageMapper;
import com.example.demo.model.ChatMessage;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.List;

@Service
public class ChatMessageService {

    @Autowired
    private ChatMessageMapper chatMessageMapper;

    public List<ChatMessage> getMessages(String user1, String user2) {
        return chatMessageMapper.findByUsers(user1, user2);
    }

    public void saveMessage(ChatMessage message) {
        message.setTimestamp(LocalDateTime.now());
        message.setSeen(false);
        chatMessageMapper.insert(message);
    }
}