## Taipei MRT Project
**104501204 EE3B 李安宸 Jerry, Lee**

This project is evalute the ticket prices, how long it take, and all the station it passed from a station to another.
Use adjacency lists to store the data.
</br>這個Project是計算台北捷運站到站的票價、搭乘時間及路過站點。使用鄰接串列儲存資料。

The data of **DISTANCE** is base on this [website](http://data.but.tw/trtc/price.html).</br>
The data of **TIME** is base on this [website](http://www.fgu.edu.tw/~94411002/TaipeiMRT/2-2.htm).</br>
距離的資料來自這個[網站](http://data.but.tw/trtc/price.html)。</br>
時間的資料來自這個[網站](http://www.fgu.edu.tw/~94411002/TaipeiMRT/2-2.htm)。

### How to Use  

1. Enter the start station number and end station number.
	</br>輸入搭乘及到達站的編號
2. You will see the price, time, the station it passed.
	</br>程式會show出票價，搭乘時間，以及路徑。
	
###Program Explanation

1. Read the data file.
	</br>讀檔案
2. Complute the shortest path.
	</br>計算最短路徑
3. Show the result.
	</br>顯示結果
	
There are five major function in this program.
</br>程式裡主要有5個function</br>
</br>**station* readstation(FILE *fp);**
</br>Read the data file	用於讀檔
</br></br>**void MRT(int *start, int *end);**
</br>Enter the station code	輸入起始結束站點編號
</br></br>**void ShortestPath(station *stop,int start, int end, float d[], int pre[], int time[]);**
</br> apply dijkstra's algorithm to find the shortest path	用dijkstra's algorithm找最短路徑
</br></br>**int FindPrice(float distance);**
</br>Evalute the price	計算票價
</br></br>**void PrintPath(int end, int pre[]);**
</br>Print the shortest path 印出最短路徑

###Code of stations

There are total 108 stations in Taipei MRT by now(2018/06), and I code each of them to a certain number.
</br>台北捷運總共有108個站點，在這程式中，每個站都用一個數字代替。

**淡水信義線(R)**

| code    | station   | number |
|:-------:|:---------:|:------:|
|1			|淡水		  |R28		 |
|2			|紅樹林		  |R27		 |
|3			|竹圍		  |R26		 |
|4			|關渡		  |R26		 |
|5			|忠義		  |R25		 |
|6			|復興崗      |R24		 |
|7			|新北投      |R22A    |
|8			|北投		  |R22		 |
|9			|奇岩		  |R21		 |
|10			|唭哩岸      |R20		 |
|11			|石牌		  |R19		 |
|12			|明德		  |R18		 |
|13			|芝山		  |R17		 |
|14			|士林		  |R16		 |
|15			|劍潭		  |R15		 |
|16			|圓山		  |R14		 |
|17			|民權西路	  |R13		 |
|18			|雙連		  |R12		 |
|19			|中山		  |R11		 |
|20			|台北車站    |R10		 |
|21			|台大醫院    |R09		 |
|22			|中正紀念堂  |R08		 |
|23			|東門		  |R07		 |
|24			|大安森林公園 |R06		 |
|25			|大安		  |R05		 |
|26			|信義安和	  |R04		 |
|27			|台北101/世貿|R03		 |
|28			|象山		  |R02		 |
**松山新店線(G)**

| code    | station   | number |
|:-------:|:---------:|:------:|
|	29	|	松山	|	G19
|	30	|	南京三民	|	G18
|	31	|	台北小巨蛋	|	G17
|	32	|	南京復興	|	G16
|	33	|	松江南京	|	G15
|	19	|	 中山	|	G14
|	34	|	北門	|	G13
|	35	|	西門	|	G12
|	36	|	小南門	|	G11
|	22	|	中正紀念堂	|	G10
|	37	|	古亭	|	G09
|	38	|	台電大樓	|	G08
|	39	|	公館	|	G07
|	40	|	萬隆	|	G06
|	41	|	景美	|	G05
|	42	|	大坪林	|	G04
|	43	|	七張	|	G03
|	44	|	小碧潭	|	G03A
|	45	|	新店區公所	|	G02
|	46	|	新店	|	G01
**板南線(BL)**

| code    | station   | number |
|:-------:|:---------:|:------:|
|	47	|	頂埔	|	BL01
|	48	|	永寧	|	BL02
|	49	|	土城	|	BL03
|	50	|	海山	|	BL04
|	51	|	亞東醫院	|	BL05
|	52	|	府中	|	BL06
|	53	|	板橋	|	BL07
|	54	|	新埔	|	BL08
|	55	|	江子翠	|	BL09
|	56	|	龍山寺	|	BL10
|	35	|	西門	|	BL11
|	20	|	台北車站	|	BL12
|	57	|	善導寺	|	BL13
|	58	|	忠孝新生	|	BL14
|	59	|	忠孝復興	|	BL15
|	60	|	忠孝敦化	|	BL16
|	61	|	國父紀念館	|	BL17
|	62	|	市政府	|	BL18
|	63	|	永春	|	BL19
|	64	|	後山埤	|	BL20
|	65	|	昆陽	|	BL21
|	66	|	南港	|	BL22
|	67	|	南港展覽館	|	BL23
**文湖線(BR)**

| code    | station   | number |
|:-------:|:---------:|:------:|
|	68	|	動物園	|	BR01
|	69	|	木柵	|	BR02
|	70	|	萬芳社區	|	BR03
|	71	|	萬芳醫院	|	BR04
|	72	|	辛亥	|	BR05
|	73	|	麟光	|	BR06
|	74	|	六張犁	|	BR07
|	75	|	科技大樓	|	BR08
|	25	|	大安	|	BR09
|	59	|	忠孝復興	|	BR10
|	32	|	南京復興	|	BR11
|	20	|	中山國中	|	BR12
|	57	|	松山機場	|	BR13
|	58	|	大直	|	BR14
|	59	|	劍南路	|	BR15
|	60	|	西湖	|	BR16
|	61	|	港墘	|	BR17
|	62	|	文德	|	BR18
|	63	|	內湖	|	BR19
|	64	|	大湖公園	|	BR20
|	65	|	葫洲	|	BR21
|	66	|	東湖	|	BR22
|	67	|	南港軟體園區	|	BR23
|	67	|	南港展覽館	|	BR24
**中和新蘆線(O)**

| code    | station   | number |
|:-------:|:---------:|:------:|
|	88	|	南勢角	|	O01
|	89	|	景安	|	O02
|	90	|	永安市場	|	O03
|	91	|	頂溪	|	O04
|	37	|	古亭	|	O05
|	23	|	東門	|	O06
|	58	|	忠孝新生	|	O07
|	33	|	松江南京	|	O08
|	92	|	行天宮	|	O09
|	93	|	中山國小	|	O10
|	17	|	民權西路	|	O11
|	94	|	大橋頭	|	O12
|	95	|	台北橋	|	O13
|	96	|	菜寮	|	O14
|	97	|	三重	|	O15
|	98	|	先嗇宮	|	O16
|	99	|	頭前庄	|	O17
|	100	|	新莊	|	O18
|	101	|	輔大	|	O19
|	102	|	丹鳳	|	O20
|	103	|	迴龍	|	O21
|	104	|	三重國小	|	O50
|	105	|	三和國中	|	O51
|	106	|	徐匯國中	|	O52
|	107	|	三民高中	|	O53
|	108	|	蘆洲	|	O54

###Data.txt
The contest of data file is like below：
</br>資料型態如下：</br>

.code	Number-of-Route
</br>/connect-1-code	distance-2	time-2
</br>/connect-2-code	distance-2	time-2
					
