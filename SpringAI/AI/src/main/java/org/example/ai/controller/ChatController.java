package org.example.ai.controller;

import org.springframework.ai.chat.client.ChatClient;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import reactor.core.publisher.Flux;

@RestController
@RequestMapping("/ai")
public class ChatController {
    @Autowired
    private ChatClient chatClient;
    @RequestMapping("/chat")
    public Flux<String> chat(String prompt) {
        return chatClient
                .prompt()
                .user(prompt)
                .stream()
                .content();
    }
}
