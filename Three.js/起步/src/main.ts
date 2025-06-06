// import { render } from 'vue';
// import './style.css'
// import *as THREE from "three"
// //创建场景
// const scene = new THREE.Scene();
// //创建相机
// const camera = new THREE.PerspectiveCamera(
//     75, 
//     window.innerWidth / window.innerHeight, 
//     0.1, 
//     1000
// );

// const renderer = new THREE.WebGLRenderer();
// renderer.setSize(window.innerWidth, window.innerHeight);
// document.body.appendChild(renderer.domElement);

// //创建几何体
// const geometry = new THREE.BoxGeometry(2, 2, 2);
// const material = new THREE.MeshBasicMaterial({color: 0x00ff00});
// const cube = new THREE.Mesh(geometry, material);
// //将几何体添加到场景中
// scene.add(cube);
// //添加相机位置
// camera.position.z = 5;
// //渲染函数
// function change()
// {
//     requestAnimationFrame(change);
//     cube.rotation.x += 0.01;
//     cube.rotation.y += 0.01;
//     renderer.render(scene, camera);
// }

// //渲染场景
// renderer.render(scene, camera);
// change();

// import * as THREE from 'three';

// // 创建场景
// const scene = new THREE.Scene();

// // 创建相机
// const camera = new THREE.PerspectiveCamera(
//   75,
//   window.innerWidth / window.innerHeight,
//   0.1,
//   1000
// );
// camera.position.z = 10;

// // 创建渲染器
// const renderer = new THREE.WebGLRenderer({ antialias: true });
// renderer.setSize(window.innerWidth, window.innerHeight);
// document.body.appendChild(renderer.domElement);

// // 创建三个球体
// const createPlanet = (color, radius = 0.5) => {
//   const geometry = new THREE.SphereGeometry(radius, 32, 32);
//   const material = new THREE.MeshBasicMaterial({ color });
//   return new THREE.Mesh(geometry, material);
// };

// const planet1 = createPlanet(0xff0000, 0.9); // 红色
// const planet2 = createPlanet(0x00ff00, 0.6); // 绿色
// const planet3 = createPlanet(0x0000ff, 0.7); // 蓝色

// scene.add(planet1);
// scene.add(planet2);
// scene.add(planet3);

// // 定义轨道参数
// const orbits = [
//   { mesh: planet1, radius: 4, speed: 0.01, angle: 0 },
//   { mesh: planet2, radius: 3, speed: 0.015, angle: Math.PI },
//   { mesh: planet3, radius: 2, speed: 0.02, angle: Math.PI / 2 },
// ];

// // 渲染循环
// function animate() {
//   requestAnimationFrame(animate);

//   // 更新每个行星的位置
//   orbits.forEach((orbit) => {
//     orbit.angle += orbit.speed;
//     orbit.mesh.position.x = Math.cos(orbit.angle) * orbit.radius;
//     orbit.mesh.position.y = Math.sin(orbit.angle) * orbit.radius;
//   });

//   renderer.render(scene, camera);
// }

// animate();
// import * as THREE from 'three';

// // 场景
// const scene = new THREE.Scene();

// // 相机 - 设置斜视角
// const camera = new THREE.PerspectiveCamera(
//   45, // 视野角度
//   window.innerWidth / window.innerHeight,
//   0.1,
//   1000
// );

// // 把相机位置拉远，并设置一个斜视角
// camera.position.set(15, 10, 15); // x=15, y=10, z=15，形成一个俯视+侧视的角度
// camera.lookAt(0, 0, 0); // 看向原点（太阳的位置）

// // 渲染器
// const renderer = new THREE.WebGLRenderer({ antialias: true });
// renderer.setSize(window.innerWidth, window.innerHeight);
// document.body.appendChild(renderer.domElement);

// // 创建星球函数
// function createPlanet(color, radius) {
//   const geometry = new THREE.SphereGeometry(radius, 32, 32);
//   const material = new THREE.MeshBasicMaterial({ color });
//   return new THREE.Mesh(geometry, material);
// }

// // 太阳
// const sun = createPlanet(0xffff00, 1.5);
// scene.add(sun);

// // 行星数据
// const planets = [
//   { name: 'planet1', color: 0xff0000, radius: 0.3, orbitRadius: 4, speed: 0.01 },
//   { name: 'planet2', color: 0x00ff00, radius: 0.25, orbitRadius: 6, speed: 0.008 },
//   { name: 'planet3', color: 0x0000ff, radius: 0.2, orbitRadius: 8, speed: 0.005 },
// ];

// // 创建每个行星并加入场景
// planets.forEach((data) => {
//   data.mesh = createPlanet(data.color, data.radius);
//   scene.add(data.mesh);
// });

// // 动画循环
// function animate() {
//   requestAnimationFrame(animate);

//   // 更新行星位置
//   planets.forEach((data) => {
//     data.angle = (data.angle || 0) + data.speed;
//     data.mesh.position.x = Math.cos(data.angle) * data.orbitRadius;
//     data.mesh.position.y = 0; // 所有行星在同一平面上绕行
//     data.mesh.position.z = Math.sin(data.angle) * data.orbitRadius;
//   });

//   renderer.render(scene, camera);
// }

// animate();

// // 响应窗口大小变化
// window.addEventListener('resize', () => {
//   camera.aspect = window.innerWidth / window.innerHeight;
//   camera.updateProjectionMatrix();
//   renderer.setSize(window.innerWidth, window.innerHeight);
// });
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';

// 场景
const scene = new THREE.Scene();
scene.background = new THREE.Color(0x000011); // 深蓝色背景，比纯黑更舒服

// 相机
const camera = new THREE.PerspectiveCamera(
  45,
  window.innerWidth / window.innerHeight,
  0.1,
  1000
);
camera.position.set(0, 50, 120);
camera.lookAt(0, 0, 0);

// 渲染器
const renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// 控制器（允许鼠标拖动视角）
const controls = new OrbitControls(camera, renderer.domElement);
controls.enableDamping = true;

// 光源 - 点光源模拟太阳发光
const light = new THREE.PointLight(0xffffff, 3, 0);
light.position.set(0, 0, 0);
scene.add(light);

// 添加环境光，让暗面也能看清楚一点
scene.add(new THREE.AmbientLight(0x888888));

// 太阳
const sunGeometry = new THREE.SphereGeometry(4, 64, 64);
const sunMaterial = new THREE.MeshBasicMaterial({ color: 0xffff00 });
const sun = new THREE.Mesh(sunGeometry, sunMaterial);
scene.add(sun);

// 行星数据（name, distanceFromSun, size, color）
const planetsInfo = [
  { name: "水星", distance: 10, size: 1.2, color: 0x7f7f7f },
  { name: "金星", distance: 15, size: 2.0, color: 0xffcc99 },
  { name: "地球", distance: 20, size: 2.2, color: 0x3399ff },
  { name: "火星", distance: 25, size: 1.5, color: 0xff3300 },
  { name: "木星", distance: 35, size: 6.0, color: 0xffcc66 },
  { name: "土星", distance: 45, size: 5.0, color: 0xffddaa },
  { name: "天王星", distance: 55, size: 3.5, color: 0x66ffff },
  { name: "海王星", distance: 65, size: 3.5, color: 0x3366cc }
];

// 存储行星对象和角度
const planets: { mesh: THREE.Mesh<THREE.SphereGeometry, THREE.MeshStandardMaterial, THREE.Object3DEventMap>; sprite: THREE.Sprite<THREE.Object3DEventMap>; angle: number; speed: number; distance: number; size: number; }[] = [];

planetsInfo.forEach(info => {
  const geometry = new THREE.SphereGeometry(info.size, 64, 64);
  const material = new THREE.MeshStandardMaterial({ color: info.color });
  const planet = new THREE.Mesh(geometry, material);

  // 初始位置在 X 轴上
  planet.position.x = info.distance;
  scene.add(planet);

  // 创建轨道
  const orbitGeometry = new THREE.RingGeometry(info.distance - 0.2, info.distance + 0.2, 128);
  const orbitMaterial = new THREE.MeshBasicMaterial({
    color: 0xffffff,
    side: THREE.DoubleSide,
    transparent: true,
    opacity: 0.2
  });
  const orbit = new THREE.Mesh(orbitGeometry, orbitMaterial);
  orbit.rotation.x = Math.PI / 2; // 让轨道环水平
  scene.add(orbit);

  // 创建名字标签（使用 Sprite）
  const canvas = document.createElement('canvas');
  const ctx = canvas.getContext('2d');
  ctx.font = 'bold 24px Arial';
  ctx.fillStyle = 'white';
  ctx.fillText(info.name, 0, 24);
  const texture = new THREE.CanvasTexture(canvas);
  const spriteMaterial = new THREE.SpriteMaterial({ map: texture });
  const sprite = new THREE.Sprite(spriteMaterial);
  sprite.scale.set(4, 2, 1); // 调整大小
  sprite.position.copy(planet.position).add(new THREE.Vector3(0, info.size + 2, 0));
  scene.add(sprite);

  // 存储信息
  planets.push({
    mesh: planet,
    sprite: sprite,
    angle: Math.random() * Math.PI * 2,
    speed: 0.005 / (info.distance / 20),
    distance: info.distance,
    size: info.size
  });
});

// 动画循环
function animate() {
  requestAnimationFrame(animate);

  // 更新每个行星的位置
  planets.forEach(p => {
    p.angle += p.speed;
    p.mesh.position.x = Math.cos(p.angle) * p.distance;
    p.mesh.position.z = Math.sin(p.angle) * p.distance;

    // 同步名字位置
    p.sprite.position.x = p.mesh.position.x;
    p.sprite.position.z = p.mesh.position.z;
    p.sprite.position.y = p.size + 2;
  });

  controls.update(); // 必须加这一句才能拖动视角
  renderer.render(scene, camera);
}

animate();

// 响应窗口变化
window.addEventListener('resize', () => {
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(window.innerWidth, window.innerHeight);
});