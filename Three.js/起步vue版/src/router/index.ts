import { create } from "lodash";
import { createRouter, createWebHashHistory} from "vue-router";

const router=createRouter(
    {
        history:createWebHashHistory(),
        routes:[
            {
                path:'/',
                component:()=>import('../pages/login.vue')
                
            },
            {
                path:'/reg',
                component:()=>import('../pages/reg.vue')
            },
            {
                path:'/work',
                component:()=>import('../pages/work.vue')
            },
        ]
    }
)
export default router