const app = Vue.createApp({
    //data: function(){} as primitive alternative
    data() {
        return {
            //Uses {{ atributeName }}
            courseGoalA: 'Finished the course',
            //Uses v-html=" method/atributeName "
            courseGoalB: 'Master Vue!',
            //Uses v-bind:
            vueLink: 'https://vuejs.org/'
        };
    },
    //Functions
    methods: {      //Uses {{ methodName() }}
        outputGoal() {
            const randomNumber = Math.random();
            if (randomNumber < 0.5){
                //return 'Learn Vue!';
                return this.courseGoalA;
            } else {
                //return 'Master Vue!';
                return this.courseGoalB;
            }
        }
    }
});

app.mount('#user-goal');