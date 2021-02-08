var results = "",str="",flag=0;
function calculater(){
    if(flag)del();
    var s=event.srcElement.innerText;
    if(s.length>1||results.length>21||(str==""&&(s=="+"||s=="-"||s=="×"||s=="÷"))){del();return;}
    if(s=="="){resultcalculate();return;}
    str+=s,display1.innerText = str;
    if(s=="×")s="*";
    if(s=="÷")s="/";
    results+=s;
}
function calculater1(s){
    if(flag)del();
    if(s.length>1||results.length>21||(str==""&&(s=="+"||s=="-"||s=="×"||s=="÷"))){del();return;}
    if(s=="="){resultcalculate();return;}
    str+=s,display1.innerText = str;
    if(s=="×")s="*";
    if(s=="÷")s="/";
    results+=s;
}
function resultcalculate(){
    if(results==""||flag){
        display1.innerText="0";
        return;
    }
    flag=1;
    var calresults=eval(results);
    calresults=String(calresults).replace(/^(.*\..{4}).*$/,"$1");
    var out=Number(calresults);
    if(out.length>21){del();return;}
    display1.innerText =out;
}
function del(){
    display1.innerText="0";
    str=results="",flag=0;
}
function color1(s){
    document.getElementById(s).style.background="#636363";
    setTimeout(function(){document.getElementById(s).style.background="#434343";},100);
}
function color2(s){
    document.getElementById(s).style.background="#787878";
    setTimeout(function(){document.getElementById(s).style.background="#636363";},100);
}
function keyDown(e){
    var keycode=e.which || event.keyCode,num="";
    console.log("keycode:"+keycode);
    switch(keycode){
        case 96:num="0";color1(num);break;
        case 97:num="1";color1(num);break;
        case 98:num="2";color1(num);break;
        case 99:num="3";color1(num);break;
        case 100:num="4";color1(num);break;
        case 101:num="5";color1(num);break;
        case 102:num="6";color1(num);break;
        case 103:num="7";color1(num);break;
        case 104:num="8";color1(num);break;
        case 105:num="9";color1(num);break;
        case 106:num="×";color2(num);break;
        case 107:num="+";color2(num);break;
        case 109:num="-";color2(num);break;
        case 110:num=".";color1(num);break;
        case 111:num="÷";color2(num);break;
        case 13:num="=";color1(num);break;
        default:num="清除";color2("清除");break;
    }
    if(num!="")
    calculater1(num);
}
document.onkeydown=keyDown;