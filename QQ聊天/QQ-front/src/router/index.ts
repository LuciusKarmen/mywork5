import { createRouter } from 'vue-router'
import { createWebHistory } from 'vue-router'

export default createRouter({
  history: createWebHistory(),
  routes: [
    {
      path: '/',
      component: () => import('../components/home.vue'),
    },
  ],
})
