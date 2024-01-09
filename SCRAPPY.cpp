#include<simplecpp>

main_program
{
initCanvas("GAMEPLAY",800,600);

//HOME PAGE
for(int f=0; f<8888; f++)
{
Rectangle bkgrd(400,300,810,610);
bkgrd.setColor(COLOR("blue"));
bkgrd.setFill();

Rectangle game(400,50,400,100);
game.setColor(COLOR("yellow"));
game.setFill();
Text gamename(400,50,"SCRAPPY");
gamename.imprint();
gamename.scale(5);

Rectangle play(400,200,190,40);
play.setFill();
play.setColor(COLOR("white"));

Text playgame(400,200,"Play Game");   //to start the game

Rectangle inst(400,300,190,40);
inst.setFill();
inst.setColor(COLOR("white"));

Text instr(400,300,"Instructions");   //to guide players

Rectangle exit(400,400,190,40);
exit.setFill();
exit.setColor(COLOR("white"));

Text exits(400,400,"Exit");           //to exit the game


Rectangle cred(400,500,190,40);
cred.setColor(COLOR("white"));
cred.setFill();
Text credt(400,500,"Credits");       //credits

int clickPos=getClick();
int cx=clickPos/65536;
int cy=clickPos%65536;

//INSTRUCTIONS
if(cx>300&&cx<500&&cy>280&&cy<320)
{
playgame.hide();
instr.hide();
exits.hide();
credt.hide();
play.hide();
inst.hide();
exit.hide();
cred.hide();

Text bak1(270,150,"Click anywhere to return to homepage");

Rectangle ins(350,270,420,50);
ins.setColor(COLOR("white"));
ins.setFill();

Text in(350,270,"Press the SPACEBAR to go up and leave to go down");

Rectangle res(350,370,420,50);
res.setColor(COLOR("white"));
res.setFill();
Text re(350,370,"Press key 'r' to go back to homepage in the middle of the game");

int clickPos=getClick();
}

//GAMEPLAY
if(cx>300&&cx<500&&cy>180&&cy<220)
{
playgame.hide();
instr.hide();
exits.hide();
credt.hide();
game.hide();
play.hide();
inst.hide();
exit.hide();
cred.hide();
gamename.hide();

//creating 3 obstacles
Rectangle obs1(810,90,20,80), obs2(810,300,20,80), obs3(810,510,20,80);
obs1.setColor(COLOR("black"));
obs1.setFill();

obs2.setColor(COLOR("black"));
obs2.setFill();

obs3.setColor(COLOR("black"));
obs3.setFill();

Rectangle obsup(400,25,800,50), obsdown(400,575,800,50);
obsup.setColor(COLOR("black"));
obsup.setFill();
obsdown.setColor(COLOR("black"));
obsdown.setFill();

double obs1x=300,obs2x=600,obs3x=900,obs1y=100,obs2y=randuv(50,550),obs3y=randuv(50,550);
double obssp=3;

// Array for coordinates of helicopter in two different positions.
double ycord = 300;
double a[19][2]={{0,-50},{-30,-45},{-30,-55},{30,-45},{30,-55},{0,-50},{0,-30},{25,-30},{50,0},{25,30},{-25,30},{-50,5},{-80,5},{-90,20},{-90,-20},{-80,-5},{-50,-5},{-25,-30},{0,-30}};
double b[19][2]={{0,-50},{5,-35},{-5,-35},{5,-65},{-5,-65},{0,-50},{0,-30},{25,-30},{50,0},{25,30},{-25,30},{-50,5},{-80,5},{-90,20},{-90,-20},{-80,-5},{-50,-5},{-25,-30},{0,-30}};
Polygon heli(200,ycord,a,19);



while (true)
{
//for moving the obstcales from right to left
obs1x-=obssp;
obs2x-=obssp;
obs3x-=obssp;

if(obs1x<=0)
{
obs1x=900;
}

if(obs2x<=0)
{
obs2x=900;
}

if (obs3x<=0)
{
obs3x=900;
}

beginFrame();
obs1.reset(obs1x,obs1y,20,100);
obs2.reset(obs2x,obs2y,20,100);
obs3.reset(obs3x,obs3y,20,100);
endFrame();

//for rotating the blades of the helicopter
beginFrame();
heli.reset(200,ycord,a,19);
heli.setColor(COLOR("yellow"));
heli.setFill();
endFrame();

beginFrame();
heli.reset(200,ycord,b,19);
heli.setColor(COLOR("yellow"));
heli.setFill();
endFrame();

// MOVING THE HELICOPTER
XEvent e;
if (checkEvent(e))
{
if (keyPressEvent(e))
{
char c = charFromEvent(e);
if((int)c == 32)
{
ycord -= 20;  //helicopter goes up
}

if((int)c == 114)
{
break;
}
else
{
ycord += 0.8;
}
}
}
else
{
ycord += 0.8;
}

//checking for collisions
if(ycord>=520 || ycord<=105 || ((200<obs1x+100 && 200>obs1x-60) && (ycord<obs1y+95 && ycord>obs1y-70))||((200<obs2x+100 && 200>obs2x-60) && (ycord<obs2y+95 && ycord>obs2y-70)) || ((200<obs3x+100 && 200>obs3x-60) && (ycord<obs3y+95 && ycord>obs3y-70)))
{
wait(1);
Text gameover(400,300,"GAME OVER");
wait(4);
break;
}
}
}
//TO EXIT THE GAME
if(cx>300&&cx<500&&cy>380&&cy<420)
{
break;
}
if(cx>300&&cx<500&&cy>480&&cy<520)
{
playgame.hide();
instr.hide();
exits.hide();
credt.hide();
play.hide();
inst.hide();
exit.hide();
cred.hide();

Rectangle rr(400,330,300,300);
rr.setColor(COLOR("white"));
rr.setFill();
Text t1(400,250,"BY TEAM 16 DEJ");
Text t2(400,300,"DRUVI TENDULKAR(1914014)");
Text t3(400,350,"ENID FERNANDES(1914015)");
Text t4(400,400,"JAYSEL SILVEIRA(1914018)");
Text t5(400,550,"Click anywhere to return to HomePage");
int clickPos=getClick();

}
}
}
