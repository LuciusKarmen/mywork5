import *as THREE from "three"
import { useEffect } from "react";
function App(){
useEffect(()=>{
  //创建场景
const scene = new THREE.Scene();
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
const material = new THREE.MeshBasicMaterial({color: 0x00ff00});
const cube = new THREE.Mesh(geometry, material);
//将几何体添加到场景中
scene.add(cube);
//添加相机位置
camera.position.z = 5;
//渲染函数
function change()
{
    requestAnimationFrame(change);
    cube.rotation.x += 0.01;
    cube.rotation.y += 0.01;
    renderer.render(scene, camera);
}

//渲染场景
renderer.render(scene, camera);
change();
  

},[])


  return (
    <div className="App">
    </div>
  )
}



export default App;