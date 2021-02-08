var isTrue = true;
var t = 0;
var flag = 1;
var scrollFunc = function(e) {
	e = e || window.event;
	if (flag && e.wheelDelta) { //判断浏览器IE，谷歌滑轮事件               
		if (e.wheelDelta > 0) { //当滑轮向上滚动时  
			handleup();
		}
		if (e.wheelDelta < 0) { //当滑轮向下滚动时  
			handleClick();
		}
	}
}
window.onmousewheel = document.onmousewheel = scrollFunc

//以上是鼠标滚轮事件
var active = 1;
var imgs_div = document.getElementById("imgs");
var imgs = imgs_div.getElementsByTagName("ul")[0];

function get_top(i) { //获取index值对应图片的偏移量
	var num;
	//console.log("第几张图片:" + i);
	switch (i) {
		case 1:
			num = 0;
			break;
		case 2:
			num = -861;
			break;
		case 3:
			num = -1755;
			break;
		case 4:
			num = -2615.5;
			break;
		default:
			break;
	}
	return num;
}

function donghua() {
	//console.log("top距离:"+imgs.offsetTop);								//实现动画效果
	var l = get_top(active);
	//console.log("l:" + l);
	flag = 0;
	var animTimer = setInterval(function() {
		var s = imgs.offsetTop;
		imgs.style.top = s + (l - s) / 10 + "px";
		if (s - l < 10 && s - l > -10) { //如果偏移量已经等于指定好的偏移量，则清除定时器
			imgs.style.top = l + "px";
			flag = 1;
			clearInterval(animTimer); //开启定时轮播
		}
	}, 14);
}

//以上是图片切换动画


btn.onclick = function() {
	handleClick();
}

function handleClick() {
	if (flag && active < 4) {
		active = active + 1;
		donghua();

	}
}

function handleup() {
	if (flag && active > 1) {
		active = active - 1;
		donghua();
	}
}