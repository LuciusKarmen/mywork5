package com.example.demo.model;

import lombok.Data;

import java.time.LocalDateTime;

@Data
public class ChatMessage {
    private Long id;
    private String sender;
    private String recipient;
    private String content;
    private LocalDateTime timestamp;
    private boolean seen;
}
