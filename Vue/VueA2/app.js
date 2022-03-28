const app = Vue.createApp({
    data() {
        return{
            name: '',
            nameConfirmed: '',
        };
    },

    methods: {
        createAlert(){
            alert('WWuiasdf');
        },

        enterName(event){
            this.name = event.target.value;
        },

        confirmName(){
            this.nameConfirmed = this.name;
        },
    }
});

app.mount('#assignment')