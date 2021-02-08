var num = 10;
new Vue({
    el: '#app',
    data() {
        return {
            width: 'width:' + num + '%;',
            time: ''
        }
    },
    methods: {
        c(){

            this.width = 'width:' + num + '%;';
        },
        add() {
            if (num < 100) {
                num += 10;
            }
            this.c();
            console.log(num);
        },
        decrease() {
            if (num >= 0) {
                num -= 10;
            }
            this.c();
            console.log(num);
        },
        g() {
            if (num >= 0) {
                num = num * 1.5;
            }
            this.c();
            console.log(num);
        },
        go() {
            this.time = setInterval(this.g, 1500);
        }
    }
})