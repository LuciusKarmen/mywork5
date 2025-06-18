import { createApp } from 'vue'

import App from './App.vue'
import r from './router/index.ts'

createApp(App).use(r).mount('#app')
