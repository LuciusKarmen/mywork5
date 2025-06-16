<template>
  <div class="right">
    <div class="login">
      <h2>Cube通信</h2>
      <h4>---你我情谊，坚如立方</h4>

      <div class="input-group">
        <label>用户名：</label>
        <input type="text" v-model="username" placeholder="请输入用户名" />
      </div>
      <div class="input-group">
        <label>密码：</label>
        <input type="password" v-model="password" placeholder="请输入密码" />
      </div>

      <div class="button-group">
        <button @click="login">登录</button>
      </div>
    </div>
  </div>
</template>

<script setup lang="ts" name="right">
import { ref } from 'vue'
const username = ref('')
const password = ref('')
const login = () => {
  console.log(username.value, password.value)
}
</script>

<style scoped>
.right {
  position: absolute;
  right: 100px;
  top: 150px;
  width: 300px;
  padding: 30px;
  background: rgba(255, 255, 255, 0.1);
  backdrop-filter: blur(10px);
  border-radius: 16px;
  box-shadow: 0 8px 32px rgba(0, 0, 0, 0.2);
  border: 1px solid rgba(255, 255, 255, 0.3);
  color: #0ef3ff;
  font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
}

.login h2 {
  margin-bottom: 10px;
  font-size: 24px;
  font-weight: bold;
}

.login h4 {
  margin-bottom: 20px;
  font-size: 14px;
  opacity: 0.8;
}

.input-group {
  margin-bottom: 15px;
}

.input-group label {
  display: block;
  margin-bottom: 6px;
  font-size: 14px;
  color: #0ef3ff;
}

.input-group input {
  width: 100%;
  padding: 10px 12px;
  border: none;
  border-radius: 6px;
  outline: none;
  font-size: 14px;
  background-color: rgba(255, 255, 255, 0.2);
  color: #060606;
  transition: background-color 0.3s ease;
}

.input-group input::placeholder {
  color: rgba(255, 255, 255, 0.6);
}

.input-group input:focus {
  background-color: rgba(255, 255, 255, 0.3);
}

.button-group button {
  width: 100%;
  padding: 10px;
  background-color: #00bcd4;
  color: white;
  border: none;
  border-radius: 6px;
  font-size: 16px;
  cursor: pointer;
  transition: background-color 0.3s ease, transform 0.2s ease;
}

.button-group button:hover {
  background-color: #0097a7;
  transform: scale(1.02);
}

.button-group button:active {
  transform: scale(0.98);
}
</style>