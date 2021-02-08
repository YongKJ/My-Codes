<template>
    <div>
        <p>Reversed massage1:"{{reversedMessage1}}"</p>
        <p>Reversed massage2:"{{reversedMessage2()}}"</p>
        <p>{{now}}</p>
        <button @click="()=>$forceUpdate()">forceUpdate</button>
        <br />
        <input v-model="message">
    </div>
</template>

<script>
    export default {
        name:"Computed",
        data () {
            return {
                message:"hello vue"
            }
        },
        computed: {
            reversedMessage1:function () {
                console.log("执行reversedMessage1");
                return this.message.split("").reverse().join("");
            },
            now:function(){
                return Date.now();
            }
        },
        methods:{
            reversedMessage2:function(){
                console.log("执行reversedMessage2");
                return this.message.split("").reverse().join("");
            }
        }
    }
</script>

<style lang="scss" scoped>

</style>