import { createRouter, createWebHistory } from 'vue-router'

const r = createRouter({
  history: createWebHistory(),
  routes: [
    {
      path: '/',
      name: 'home',
      component: () => import('../components/face.vue')
    },
    {
      path: '/our',
      name: 'our',
      component: () => import('../components/our.vue')
    }
  ]
})

export default r;