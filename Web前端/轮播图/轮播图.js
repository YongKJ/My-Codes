function go(){
	var imgs_div=document.getElementById("imgs");
	var spot_div=document.getElementById("spot");
	var imgs=imgs_div.getElementsByTagName("ul")[0];
	var spot=spot_div.getElementsByTagName("ul")[0];
	var pre=document.getElementById("pre");
	var next=document.getElementById("next");
	var timer,animTimer,index=1;					//timer为控制每隔两秒点击一张图片的定时器，animTimer为控制动画效果的定时器
	play();
	document.onkeydown=keyDown;	
	function keyDown(){ 
	console.log("event.keyCode"+event.keyCode);
	if(event.keyCode==37)pre.onclick();				//按右键时显示上一张图片	
	if(event.keyCode==39)next.onclick();			//按左键时显示下一张图片
	}
	pre.onclick=function(){
		init_imgs(get_left(index));			//清除定时器，并且显示当前图片
		index-=1;
		if(index<1)index=5;
		var left=get_left(index);
		//console.log("left"+left);
		donghua(left);						//设置动画，显示下一张图片
		spot_show(index);					//数字的背景颜色
	}
	next.onclick=function(){
		init_imgs(get_left(index));			//清除定时器，并且显示当前图片
		index+=1;
		if(index>5)index=1;
		var left=get_left(index);
		console.log("left"+left);
		donghua(left);						//设置动画，显示下一张图片
		spot_show(index);					//数字的背景颜色
	}
	for(var i=0;i<spot.children.length;i++){
		spot.children[i].index=i+1;
		spot.children[i].onmouseover=function(){			//鼠标移入数字时
			//console.log("this.index"+this.index);
			index=this.index;								//更新index值
			init_imgs(get_left(this.index));				//清除定时器，并且显示当前图片
			spot_show(this.index);							//数字的背景颜色
			//console.log("get_left(i+1)"+get_left(i+1));
		};
		spot.children[i].onmouseout=play;					//鼠标移出数字时
	}
	function get_left(i){									//获取index值对应图片的偏移量
		var num;
		switch(i){
			case 1:num=-40;break;
			case 2:num=-1320;break;
			case 3:num=-2600;break;
			case 4:num=-3880;break;
			case 5:num=-5160;break;
			default:break;
		}
		return num;
	}
	function play(){												//定时轮播
		timer=setInterval("next.onclick()",2000);
	}			
	function donghua(l){											//实现动画效果
		animTimer=setInterval(function(){
			var s=imgs.offsetLeft;
			imgs.style.left=s+(l-s)/10+"px";
			if(s-l<10&&s-l>-10){									//如果偏移量已经等于指定好的偏移量，则清除定时器
				imgs.style.left=l+"px";
				clearInterval(animTimer);
				play();												//开启定时轮播
			}
		},20);
	}
	function init_imgs(l){											//清除定时器，并且显示当前图片
		clearInterval(timer);
		clearInterval(animTimer);
		imgs.style.left=l+"px";
	}
	function spot_show(i){											//数字的背景颜色
		for(var j=0;j<spot.children.length;j++)
			spot.children[j].children[0].className="hidden";
		spot.children[i-1].children[0].className="current";
	}
}