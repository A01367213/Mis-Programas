const app = Vue.createApp({
  data() {
    return {
      counter: 30,
      name : '',
      confirmedName: '',
    };
  },

  //Methods can be called with or without ()
  methods: {
    confirmInput(){
      this.confirmedName = this.name;
    },

    addCounter(num){
      this.counter = this.counter + num;
    },

    substractCounter(num){
      this.counter = this.counter - num;
    },

    setName(event, lastName){
      this.name = event.target.value + ' ' + lastName;
    },

    submitForm(){
      alert('Submitted!');
    }
    
    //Traditional
    // submitForm(event){
    //   event.preventDefault();
    //   alert('Submitted!');
    // }
  }
});

app.mount('#events');
