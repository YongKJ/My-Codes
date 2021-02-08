<template>
  <div id="index">
    <a-tabs style="text-align:center">
      <a-tab-pane key="props" tab="属性">
          <Props 
            name="Hello vue!"
            :type="type"
            :is-visible="false"
            :on-change="handlePropChange"
            title="属性Demo"
            class="test1"
            :class="['test2']"
            :style="{margin:'20px'}"
            style="margin-top:10px"
          />
      </a-tab-pane>
      <a-tab-pane key="enent" tab="事件">
          <Event :name="name" @change="handleEventChange" />
      </a-tab-pane>
      <a-tab-pane key="slot" tab="插槽">
        <h2>2.6 新语法</h2>
        <SlotDemo>
          <p>default slot</p>
          <template v-slot:title>
            <p>title slot1</p>
            <p>title slot2</p>
          </template>
          <template v-slot:item="props">
            <p>item slot-scope {{props}}</p>
          </template>
        </SlotDemo>
        <br />
        <h2>老语法</h2>
        <SlotDemo>
          <p>default slot</p>
          <p slot="title">title slot1</p>
          <p slot="title">title slot2</p>
          <p slot="item" slot-scope="props">item slot-scope {{props}}</p>
        </SlotDemo>
      </a-tab-pane>
      <a-tab-pane key="bigProps" tab="大属性">
          <BigProps 
            :name="bigPropsName"
            :on-change="handleBigPropsChange"
            :slot-default="getDefault()"
            :slot-title="getTitle()"
            :slot-scope-item="getItem"
          />
      </a-tab-pane>
      <a-tab-pane key="PersonalInfo" tab="个人信息">
        <PersonalInfo v-model="phoneInfo" :zip-code.sync="zipCode"/>
        <PersonalInfo 
          :phone-info="phoneInfo"
          :zip-code="zipCode"
          @change="val=>(phoneInfo=val)"
          @update:zipCode="val=>(zipCode=val)"
        />


        phoneInfo:{{phoneInfo}}
        <br />
        zipCode:{{zipCode}}
      </a-tab-pane>
      <a-tab-pane key="PropsAndData" tab="子组件的更新">
        <p>
          <button @click="handleNameChange">change this.name</button>
          <button @click="handleInfoChange">change this.info</button>
          <button @click="handleListChange">change this.list</button>
        </p>
        <PropsAndData :name="name" :info="info"  :list="list" />
      </a-tab-pane>
      <a-tab-pane key="Computed" tab="计算属性">
        <Computed />
      </a-tab-pane>
      <a-tab-pane key="Watch" tab="侦听器">
        <Watch />
      </a-tab-pane>
    </a-tabs>
  </div>
</template>

<script>
import Slot from "./components/Slot";
import Props from "./components/Props";
import Event from "./components/Event";
import BigProps from "./components/BigProps";
import PersonalInfo from "./components/PersonalInfo";
import PropsAndData from "./components/PropsAndData";
import Computed from "./components/Computed";
import Watch from "./components/Watch";
let name = "world";
    export default {
        components:{
            Props,
            Event,
            BigProps,
            SlotDemo:Slot,
            PersonalInfo,
            PropsAndData,
            Computed,
            Watch
        },
        data () {
          this.name = name;
            return {
                //name:"",
                type:"success",
                bigPropsName:"hello world!",
                phoneInfo:{
                  areaCode:"+86",
                  phone:""
                },
                zipCode:"",
                info:{},
                list:[]
            }
        },
        methods: {
            handlePropChange(val){
                this.type = val;
            },
            handleEventChange(val){
                this.name = val;
                console.log("触发@change事件");
            },
            handleBigPropsChange(val){
                this.bigPropsName=val;
            },
            getDefault(){
                return [
                  this.$createElement("p","default slot")
                ];
            },
            getTitle(){
                return [
                    this.$createElement("p","title slot1"),
                    this.$createElement("p","title slot2")
                ];
            },
            getItem(props){
                return [
                    this.$createElement("p",`item slot-scop ${JSON.stringify(props)}`)
                ];
            },
            handleNameChange(){
               this.name = "vue" + Date.now();
               console.log("this.name发生了变化，但是并没有触发子组件更新",this.name);
            },
            handleInfoChange(){
               this.info.number = 1;
               console.log("this.info发生了变化，但是并没有触发子组件更新",this.info);
            },
            handleListChange(){
               this.list.push(1,2,3);
               console.log("this.name发生了变化，但是并没有触发子组件更新",this.list );
            }
            
        }
    };
</script>

<style lang="scss" scoped>
</style>