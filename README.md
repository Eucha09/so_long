# so_long

miniLibX를 사용하여 간단한 2D 게임 개발

## miniLibX

miniLibX는 X-Window와 Cocoa에 대한 지식 없이도 화면에서 무엇인가를 렌더링하기 위한 가장 기본적인 작업을 수행할 수 있는 작은 그래픽 라이브러리

참고 문서 : https://harm-smits.github.io/42docs/libs/minilibx/introduction.html

# Pac-Man (so_long)

<div align="center">
  <img src="screenshot/play_classic.png" width="600"/>
</div>

## Introduction

Pac-Man을 클론코딩하여 간단한 2D 게임을 제작하였다.

플레이어의 목표는 고스트들을 피해 최소한의 움직임으로 모든 먹이를 먹고 출구로 탈출하는 것이다.

## Getting Started (Mac)

### Clone repository

```
git clone https://github.com/Eucha09/so_long.git
cd so_long
```

### Install miniLibX

```
cd mlx
make
cd ..
```

### Install Pac-Man(so_long)

```
make bonus
```

### Usage

```
./so_long [맵 파일 경로] 
```
ex)
```
./so_long maps/classic.ber
```

### How to play

|KEYBOARD|ACTION|
|---|---|
|`W`, `↑`|Move up|
|`S`, `↓`|Move down|
|`A`, `←`|Move left|
|`D`, `→`|Move right|
|`R`|Retry game|
|`ESC`|Close the game window|

### Maps

- ```maps/tutorial1.ber```   
<img src="screenshot/maps_tutorial1.png" width="300"/>

- ```maps/tutorial2.ber```   
<img src="screenshot/maps_tutorial2.png" width="800"/>

- ```maps/classic.ber```   
<img src="screenshot/maps_classic.png" width="500"/>

- ```maps/42seoul.ber```   
<img src="screenshot/maps_42seoul.png" width="800"/>

- ```maps/survival1.ber```   
<img src="screenshot/maps_survival1.png" width="300"/>

- ```maps/survival2.ber```   
<img src="screenshot/maps_survival2.png" width="300"/>