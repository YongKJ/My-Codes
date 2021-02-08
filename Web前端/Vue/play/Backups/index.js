

new Vue({
    el:'#app',
    data () {
        return {
           show:true 
        }
    },
    methods: {
        handleClick(){
            this.show = !this.show;
        }
    }
})

