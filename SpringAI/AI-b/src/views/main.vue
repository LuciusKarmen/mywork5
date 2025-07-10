<template>
  <div class="main-container">
    <div class="top">
      <div class="title">你我一起，改变世界</div>
    </div>
    <div class="left">
      <div class="title">光明模型</div>
      <div class="title">使用指南</div>
      <div class="title" @click="go">关于我们</div>
    </div>
    <div class="main">
      <div class="content">{{ response }}</div>
      <div class="question">
        <input type="text" placeholder="请输入问题" v-model="prompt" />
        <button @click="sendPrompt">提交</button>
      </div>
    </div>
  </div>
</template>

<script lang="ts" setup>
import { ref } from 'vue'
import axios from 'axios'
import { useRouter } from 'vue-router'

const prompt = ref('')
const response = ref('')
const router = useRouter()
const go = () => {
  router.push('/our')
}

const sendPrompt = async () => {
  await axios
    .get('/api/ai/chat', {
      params: {
        prompt: prompt.value,
      },
    })
    .then((res) => {
      response.value = res.data
      console.log(res)
      prompt.value = ''
    })
    .catch((err) => {
      console.log(err)
    })
}
</script>
<style lang="scss" scoped>
.main-container {
  width: 100vw;
  height: 100vh;
  display: flex;
  flex-direction: column;
  background-color: #f8f9fa;
  font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
  .top {
    width: 100%;
    height: 5vh;
    background: linear-gradient(to right, #6a11cb, #2575fc);
    display: flex;
    align-items: center;
    justify-content: center;
    color: white;
    font-size: 1.5rem;
    font-weight: bold;
    box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);

    .title {
      background: linear-gradient(to right, #00c9ff, #ffb7ed);
      -webkit-background-clip: text;
      -webkit-text-fill-color: transparent;
    }
  }
  .left {
    width: 20%;
    height: 95vh;
    background-color: #ffffff;
    border-right: 1px solid #e0e0e0;
    box-shadow: 2px 0 6px rgba(0, 0, 0, 0.05);
    display: flex;
    flex-direction: column;
    align-items: flex-start;
    padding: 1.5rem 1rem;
    transition: all 0.3s ease;

    &:hover {
      box-shadow: 2px 0 10px rgba(0, 0, 0, 0.1);
    }

    .title {
      width: 100%;
      padding: 0.75rem 1.25rem;
      font-size: 1rem;
      color: #333;
      cursor: pointer;
      border-radius: 8px;
      margin-bottom: 0.5rem;
      transition: all 0.2s ease;
      position: relative;

      &:hover {
        background-color: #f0f0f0;
        color: #00c9ff;
      }

      &.active {
        background-color: #00c9ff;
        color: white;
        font-weight: bold;

        &::after {
          content: '';
          position: absolute;
          right: 0;
          top: 50%;
          transform: translateY(-50%);
          width: 4px;
          height: 60%;
          background-color: #ff3083;
        }
      }
    }
  }
  .main {
    width: 80%;
    height: 95vh;
    display: flex;
    flex-direction: column;
    position: absolute;
    right: 0;
    top: 5vh;

    .content {
      flex: 1;
      padding: 1.5rem;
      overflow-y: auto;
      background-color: #ffffff;
      border-radius: 8px;
      margin: 1rem;
      box-shadow: 0 2px 6px rgba(0, 0, 0, 0.05);
      font-size: 1rem;
      color: #333;
      line-height: 1.6;
      white-space: pre-wrap; // 保留换行符
      word-wrap: break-word;

      &:empty::before {
        content: attr(placeholder);
        color: #aaa;
        font-style: italic;
      }
    }
    .question {
      background: #f9f9f9;
      width: 100%;
      position: absolute;
      bottom: 0;
      left: 0;
      display: flex;
      align-items: center;
      justify-content: space-between;
      padding: 1rem;
      box-shadow: 0 -2px 10px rgba(0, 0, 0, 0.05);
      border-top: 1px solid #e0e0e0;
      z-index: 10;

      input {
        flex: 1;
        padding: 0.75rem 1rem;
        border: 1px solid #ccc;
        border-radius: 30px;
        outline: none;
        font-size: 1rem;
        background-color: #fff;
        transition: all 0.3s ease;
        margin-right: 1rem;

        &:focus {
          border-color: #ff3083;
          box-shadow: 0 0 0 3px rgba(255, 48, 131, 0.2);
        }
      }

      button {
        padding: 0.6rem 1.2rem;
        background-color: #ff3083;
        color: white;
        border: none;
        border-radius: 30px;
        cursor: pointer;
        font-weight: bold;
        transition:
          background-color 0.3s ease,
          transform 0.2s ease;

        &:hover {
          background-color: #ed7ac8;
          transform: scale(1.05);
        }

        &:active {
          transform: scale(0.98);
        }
      }
    }
  }
}
</style>
