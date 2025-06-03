document.getElementById("btn").addEventListener("click", aaa)
function user(name , age){
    this.name = name;
     this.age = age;
      this.show = function(){
        alert(this.name + " " + this.age);
    }
}
function aaa(){
     var name = document.getElementById("name").value;
     var age = document.getElementById("age").value;
     var user1 = new user(name , age);
     user1.show();
     console.log(user1);
      console.log(user);
}