
new Vue({
    el: '#app',
    data() {
        return {
            show: true,
            nav: 'background-color: #3d4450;',
            seen:false
        }
    },
    methods: {
        handleClick() {
            this.show = !this.show;
        },
        Mouse(){
            this.seen = !this.seen;
        }
    }
})

