<template>
  <div class="left"></div>
</template>

<script scoped lang="ts" name="left">


import *as THREE from "three"
//创建场景
const scene = new THREE.Scene();

//改变背景图
scene.background = new THREE.TextureLoader().load("https://tse3-mm.cn.bing.net/th/id/OIP-C.vNAdH7f8f_d7kZ0qxGVlogHaEK?r=0&rs=1&pid=ImgDetMain");


//创建相机
const camera = new THREE.PerspectiveCamera(
    75, 
    window.innerWidth / window.innerHeight, 
    0.1, 
    1000
);

const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

//创建几何体
const geometry = new THREE.BoxGeometry(2, 2, 2);
const material = new THREE.MeshBasicMaterial({color: 0x48faf1});
const cube = new THREE.Mesh(geometry, material);



//将几何体添加到场景中
scene.add(cube);
//添加相机位置
camera.position.z = 5;

  camera.position.x = 1.7; 
//渲染函数
function change()
{
    requestAnimationFrame(change);
    cube.rotation.x += 0.01;
    cube.rotation.y += 0.01;
    renderer.render(scene, camera);
}

//渲染场景

change();
</script>

<style scoped>

.left{
    position: absolute;
    left: 0;
    top: 0;
    width: 60vw;
    height:100vh;
    color: #48faf1;
}
</style>