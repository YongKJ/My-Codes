new Vue({
  el:'#progress',
  data:{
    show:true,
    n:2,
    is:[
      {a:false,m:"0%",b:"rate0"},
      {a:false,m:"15%",b:"rate1"},
      {a:true,m:"45%",b:"rate2"},
      {a:false,m:"60%",b:"rate3"},
      {a:false,m:"80%",b:"rate4"},
      {a:false,m:"100%",b:"rate5"},
    ]
  },
  methods:{
    choose(index){
      this.n=index;
      this.show=!this.show;
      for(var i=0;i<6;i++)
        this.is[i].a=i==index?true:false;
   }
 }
})
