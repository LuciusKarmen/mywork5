<template>
  <div class="game-container">
    <!-- 左右控制按钮 -->
    <button class="control-btn left-btn" @mousedown="startLeft" @mouseup="stopLeft" @touchstart="startLeft" @touchend="stopLeft">⬅️</button>
    <button class="control-btn right-btn" @mousedown="startRight" @mouseup="stopRight" @touchstart="startRight" @touchend="stopRight">➡️</button>

    <canvas ref="gameCanvas" width="300" height="500"></canvas>

    <p v-if="gameOver" class="game-over">💥 游戏结束！得分：{{ score }}</p>
    <p class="high-score">🎯 历史最高分：{{ highScore }}</p>
    <p class="high-score">QQ:33521189 关注Karmen~喵~~</p>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'

const gameCanvas = ref(null)
const ctx = ref(null)

// 小球属性
const ball = {
  x: 150,
  y: 450,
  radius: 12,
  color: '#0095DD'
}

// 移动控制
let leftPressed = false
let rightPressed = false



// 障碍物数组
const obstacles = []
const obstacleWidth = 30
const obstacleHeight = 30

// 游戏状态
const gameOver = ref(false)
const score = ref(0)
const highScore = ref(0)

// 初始化最高分
highScore.value = Number(localStorage.getItem('sandBallHighScore')) || 0

// 创建新障碍物
function createObstacle() {
  const x = Math.random() * (300 - obstacleWidth)
  obstacles.push({ x, y: -30 })
}

// 检测碰撞
function checkCollision(ball, obs) {
  return (
    ball.x + ball.radius > obs.x &&
    ball.x - ball.radius < obs.x + obstacleWidth &&
    ball.y + ball.radius > obs.y &&
    ball.y - ball.radius < obs.y + obstacleHeight
  )
}

// 绘制小球
function drawBall() {
  ctx.value.beginPath()
  ctx.value.arc(ball.x, ball.y, ball.radius, 0, Math.PI * 2)
  ctx.value.fillStyle = ball.color
  ctx.value.fill()
  ctx.value.closePath()
}

// 绘制障碍物
function drawObstacles() {
  ctx.value.fillStyle = '#8B4513'
  for (const obs of obstacles) {
    ctx.value.fillRect(obs.x, obs.y, obstacleWidth, obstacleHeight)
  }
}

// 更新画面
function update() {
  if (gameOver.value) return

  // 清除画布
  ctx.value.clearRect(0, 0, 300, 500)

  // 控制小球移动
  if (leftPressed && ball.x > 0) ball.x -= 3
  if (rightPressed && ball.x < 300) ball.x += 3

  // 绘制小球
  drawBall()

  // 更新并绘制障碍物
  for (let i = 0; i < obstacles.length; i++) {
    const obs = obstacles[i]
    obs.y += 2 // 下落速度慢一点
    drawObstacles()

    // 碰撞检测
    if (checkCollision(ball, obs)) {
      gameOver.value = true

      // 判断是否刷新了最高分
      if (score.value > highScore.value) {
        localStorage.setItem('sandBallHighScore', score.value)
        highScore.value = score.value
      }

      alert(`💥 游戏结束！得分：${score.value}\n历史最高分：${highScore.value}`)
      location.reload()
    }

    // 出界就移除并加分
    if (obs.y > 500) {
      obstacles.splice(i, 1)
      score.value++
    }
  }

  requestAnimationFrame(update)
}

// 键盘事件监听（桌面兼容）
function keyDownHandler(e) {
  if (e.key === 'ArrowLeft') leftPressed = true
  if (e.key === 'ArrowRight') rightPressed = true
}

function keyUpHandler(e) {
  if (e.key === 'ArrowLeft') leftPressed = false
  if (e.key === 'ArrowRight') rightPressed = false
}

// 控制按钮按下/释放事件
function startLeft() {
  leftPressed = true
}
function stopLeft() {
  leftPressed = false
}
function startRight() {
  rightPressed = true
}
function stopRight() {
  rightPressed = false
}

onMounted(() => {
  ctx.value = gameCanvas.value.getContext('2d')

  // 每隔一段时间创建一个障碍物
  setInterval(createObstacle, 400)

  // 启动游戏循环
  update()

  // 添加键盘事件
  document.addEventListener('keydown', keyDownHandler)
  document.addEventListener('keyup', keyUpHandler)
})
</script>

<style scoped>
.game-container {
  position: relative;
  display: flex;
  flex-direction: column;
  align-items: center;
  margin-top: 20px;
  height: 100vh;
  weight: 100vw;
}

canvas {
  background-color: #f0f0f0;
  border: 2px solid #333;
  z-index: 1;
}

.control-btn {
  position: absolute;
  top: 40%;
  transform: translateY(-50%);
  font-size: 36px;
  background-color: rgba(0, 0, 0, 0.1);
  border: none;
  padding: 20px;
  border-radius: 50%;
  z-index: 2;
}

.left-btn {
  left:10px;
}

.right-btn {
  right: 10px;
}

.game-over {
  font-size: 18px;
  color: red;
  margin-top: 10px;
}

.high-score {
  margin-top: 10px;
  font-weight: bold;
  color: green;
}
</style>