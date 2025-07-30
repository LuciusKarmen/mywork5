import { createRouter, createWebHistory } from 'vue-router'

const router = createRouter({
  history: createWebHistory(),
  routes: [
    {
      path: '/',
      name: 'start',
      component: () => import('../views/start.vue'),
    },
    {
      path: '/login',
      name: 'login',
      component: () => import('../views/login.vue'),
    },
    {
      path: '/reg',
      name: 'reg',
      component: () => import('../views/reg.vue'),
    },
    {
      path: '/our',
      name: 'our',
      component: () => import('../views/our.vue'),
    },
  ],
})
