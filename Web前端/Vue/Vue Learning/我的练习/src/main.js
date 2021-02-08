import Vue from 'vue';
//import App from './App.vue';
import antd from "ant-design-vue"
import index from './index.vue'
import "ant-design-vue/dist/antd.css";

Vue.use(antd);
Vue.config.productionTip = false

new Vue({
  render: h => h(index),
}).$mount('#index')
