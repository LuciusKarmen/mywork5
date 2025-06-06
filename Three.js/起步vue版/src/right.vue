<template>
  <div class="right">
    <div class="login">
    <div>登录界面</div>

    <div>用户名：<input type="text" v-model="username"></div>
    <div>密码：<input type="password" v-model="password"></div>
    <div><button @click="login">登录</button></div>


  </div>
  </div>
</template>

<script>

</script>

<style>
.right {
    position: absolute;
    right: 100px;
    top: 200px;
    width: 400px;
    height: 300px;
}
</style>