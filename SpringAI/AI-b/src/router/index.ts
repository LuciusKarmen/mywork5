import { createRouter, createWebHistory } from 'vue-router'
import Face from '../views/face.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: Face,
    },
    {
      path: '/main',
      name: 'main',
      component: () => import('../views/main.vue'),
    },
    {
      path: '/our',
      name: 'our',
      component: () => import('../views/our.vue'),
    },
  ],
})

export default router
