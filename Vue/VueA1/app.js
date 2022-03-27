const app = Vue.createApp({
    data(){
        return {
            name: 'Horacio',
            age:  21,
            imageURL: 'https://cdn.donmai.us/original/6b/0e/__raphtalia_tate_no_yuusha_no_nariagari_drawn_by_yazwo__6b0e91c5fefdb64d9b483159ff89528e.jpg'
        };
    },

    methods: {
        favNumber() {
            const randomNumber = Math.random();
            return randomNumber;
        },

        ageFuture() {
            const ageAux = this.age + 5;
            return ageAux;
        }
    }
});

app.mount('#assignment');