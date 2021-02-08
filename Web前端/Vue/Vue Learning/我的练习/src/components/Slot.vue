<template>
    <div>
        <slot />
        <slot name="title" />
        <slot name="item" v-bind="{value,v}" />
    </div>
</template>

<script>
    export default {
        name:"SlotDemo",
        data () {
            return {
                value:'vue',
                v:'hello'
            }
        }
    }
</script>

<style lang="scss" scoped>

</style>