# Reason Dojo - May 2020

## Table of Contents
- [Reason Dojo - May 2020](#reason-dojo---may-2020)
  - [Table of Contents](#table-of-contents)
  - [Event Details](#event-details)
    - [Description](#description)
    - [Schedule](#schedule)
    - [Location (virtual)](#location-virtual)
    - [What We're Building](#what-were-building)
    - [Socializing](#socializing)
    - [Getting Help](#getting-help)
  - [Resources](#resources)
    - [Prepping for the event](#prepping-for-the-event)
    - [Creating a Group DM on Discord](#creating-a-group-dm-on-discord)
    - [Using Tailwind](#using-tailwind)
  - [Projects Built during this Dojo](#projects-built-during-this-dojo)
  - [Contributing](#contributing)
  - [License](#license)
  - [Thanks!](#thanks)
- [ReasonReact Template](#reasonreact-template)
  - [Run](#run)

## Event Details

Below, you'll find all the information about the event itself.

### Description

Reason Dojo is a unique take on meetups. In the beginning, we'll walk you through installing Reason and setting up your IDE. After that, we'll present you with an app & requirements. We'll split everyone up into groups. Each group will have at least one experienced Reason developer. 

Your goal: build the app as a group during the allotted hacking time.

The least experienced developer will drive (i.e. write code) while the others help guide. The purpose of this is both to:
1. take the pressure off the new person (they follow the guidance of others)
2. let the others mentor and guide as they help architect the app

If you've never been done a dojo-style meetup before, it's the perfect opportunity to:
- learn + improve your Reason skills 
- help others by working as a team (with both new + experienced Reason devs)
- build something fun that you can take home

### Schedule

Below is the schedule for the event. We expect it to run for ~3hrs:
| hour     | title           | description                                                                       |
|----------|-----------------|-----------------------------------------------------------------------------------|
| 00:00:00 | Introduction    | Joe will welcome Sean to explain Reason Dojo and explain how the event will work. |
| 00:30:00 | Hacking Session | Groups will meet on Discord and get started programming.                          |
| 02:30:00 | Demos           | Sean will call groups up and have them demo their apps on Zooom.                  |
| 02:50:00 | Closing         | Sean will lead discussion on Reason feedback discussion.                          |

### Location (virtual)

This particular event is happening online using a combination of Zoom and Discord. The main sessions (Introduction, Demos, and Closing) will take place on Zoom and be recorded. The Hacking Session will take place on Discord. We encourage you to use Group DMs to coordinate with your team members over voice or video chat.

We will also have places to socialize during the event on both Discord and Zoom.

### What We're Building

During the event, we will build a web app for reminding you to take breaks (inspired by [stretchly](https://github.com/hovancik/stretchly)).

You will be tasked with completing the following requirements:

As a user, I should be able to:
- [ ]  set the frequency of my breaks (every 30 mins, every 30 secs).
- [ ]  configure how long the break should be (5 secs) - make it configurable later

As a web app, it should make sure that:
- [ ]  the notification is triggered on the interval 

As a user, I should be able to see:
- [ ]  a progress screen during the break that shows
    - [ ]  a progress bar
    - [ ]  how many mins/secs remaining
    - [ ]  an exit button

### Socializing

One of the hardest parts of virtual meeetups is creating space for free form socializing. To combat this, we will have three places you can socialize during the event:
- Zoom: we will keep the main Zoom going during the Hacking Session. Feel free to stay on and chat with others.
- Discord #general voice chat room: this is a room where you can voice chat with others
- #bikeshedding: a Discord channel that is great for chatting about anything really

### Getting Help

If you need help (technical/non-technical), we suggest following this approach:
1. Ask you group members. If they don't know, chances are they'll be able to tell you where to look/post.
2. Post in the #general channel - this is where most members hang out and will have high visibility
3. DM Joe(@jsjoeio) or Sean(@sgrove) on Discord

## Resources

Below, you'll find helpful resources for both before, during and after the event:

### Prepping for the event

Don't worry if you've never written a line of Reason before! We'll cover installing Reason and setting up your IDE during the introduction of the event. Make sure you have [Zoom](https://zoom.us/download) and [Discord](https://discordapp.com/download) installed and bring a positive mental attitude to the event! 

### Creating a Group DM on Discord 

Group DMs on Discord will be used to communicate with you and your group during the Dojo. To create a Group DM, you'll need the following:
- A Discord account ([sign up to create one](https://discordapp.com/register))
- The Discord app ([download here](https://discordapp.com/download))
- Be friends with the people who will join your group (follow [this guide](https://support.discordapp.com/hc/en-us/articles/218344397-How-do-I-add-my-friend-to-my-friends-list-) to add someone)

Now that you have that, you can create a group. Follow these steps:
1. Inside the Discord app, navigate to the Home page (click the Discord icon in the left sidebar)

![screenshot showing the Discord Home icon](images/discord-home-icon.png)

2. Under direct messages, click the "+" icon

![screenshot showing the plus icon for creating a DM on Discord](images/create-dm.png)

3. Type the username of the friends that you want to add to your group

![screenshot showing where to type the names of your group members.](images/group-dm-discord-type-name.png)

4. Click "Create Group DM" 

![screenshot showing the button to click to create a group dm on Discord](images/create-group-dm-button.png)

### Using Tailwind

If you're finding it hard to know what classes to use for Tailwind, take a look at the [bindings](https://github.com/phthhieu/re-tailwind/blob/master/src/TW.re) directly. And if you're not familiar with Tailwind CSS, take a look at [their site](https://tailwindcss.com/).   

## Projects Built during this Dojo

After this event, we will invite groups to open PRs to add links to their projects here:

## Contributing

We welcome contributions! If you would like to submit your project, fix a typo, or make a suggestion, please open a pull request. 

## License

This repo, the code and the event materials are all licensed under the MIT License. Please see [LICENSE](./LICENSE) for more details.

## Thanks!

This event wouldn't be possible with out the lovely folks from the Reason community and support form the following companies:

<table>
  <tr>
    <td align="center" bgcolor="white"><a href="https://opensource.facebook.com/">FACEBOOK Open Source</a></td>
    <td align="center"><a href="https://onegraph.com">OneGraph</a></td>
  </tr>
  <tr>
    <td style="background: white;"><img src="./images/fb-logo.png" width="200"></td>
    <td style="background: white;"><img src="https://www.onegraph.com/static/media/landing-logo-grey.a79a936f.svg" width="120"></td>
  </tr>
 </table>



-------
# ReasonReact Template

## Run

```sh
npm install
npm run server
# in a new tab
npm start
```

Open a new web page to `http://localhost:8000/`. Change any `.re` file in `src` to see the page auto-reload. **You don't need any bundler when you're developing**!
