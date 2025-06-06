import { createRouter } from "vue-router"
import  { createWebHistory } from "vue-router"
const router = createRouter({
  history: createWebHistory(),
  routes: [
    {
      path: "/",
      name: "login",
      component: () => import("../pages/login.vue"),
    },
  ],
})
export default router
