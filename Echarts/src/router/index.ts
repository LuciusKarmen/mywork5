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
      path: '/1',
      name: '11111',
      component: () => import('../views/style.vue'),
    },
    {
      path: '/2',
      name: '22222',
      component: () => import('../views/pie.vue'),
    },
    {
      path: '/3',
      name: '33333',
      component: () => import('../views/map.vue'),
    },
  ],
})
export default router
