package com.example.demo.mapper;



import com.example.demo.model.ChatMessage;
import org.apache.ibatis.annotations.*;

import java.util.List;

@Mapper
public interface ChatMessageMapper {

    @Select("SELECT * FROM chat_message WHERE (sender = #{sender} AND recipient = #{recipient}) OR (sender = #{recipient} AND recipient = #{sender}) ORDER BY timestamp")
    List<ChatMessage> findByUsers(@Param("sender") String sender, @Param("recipient") String recipient);

    @Insert("INSERT INTO chat_message(sender, recipient, content, timestamp, seen) VALUES(#{sender}, #{recipient}, #{content}, #{timestamp}, #{seen})")
    @Options(useGeneratedKeys = true, keyProperty = "id")
    void insert(ChatMessage message);
}