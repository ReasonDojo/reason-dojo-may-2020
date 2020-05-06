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
  - [FAQ](#faq)
    - [How will teams be divided up?](#how-will-teams-be-divided-up)
    - [How am I going to shared an editor or my IDE with my group memebers?](#how-am-i-going-to-shared-an-editor-or-my-ide-with-my-group-memebers)
    - [How am I going to chat with my group members?](#how-am-i-going-to-chat-with-my-group-members)
    - [How will the moderators be able to check-in with each group?](#how-will-the-moderators-be-able-to-check-in-with-each-group)
  - [Projects Built during this Dojo](#projects-built-during-this-dojo)
  - [Contributing](#contributing)
  - [License](#license)
  - [Thanks!](#thanks)

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

As a user, I should be able to see:
- [ ]  a progress screen during the break that shows
    - [ ]  a message
    - [ ]  a progress bar
    - [ ]  how many mins/secs remaining
    - [ ]  a stop button

*Stretch Goals:*

If you finish those requirements and want an extra challenge, try some of these:

As a web app, it should make sure that:
- [ ]  the notification is triggered on the interval 

### Socializing

One of the hardest parts of virtual meeetups is creating space for free form socializing. To combat this, we will have three places you can socialize during the event:
- Zoom: we will keep the main Zoom going during the Hacking Session. Feel free to stay on and chat with others.
- Discord #general voice chat room: this is a room where you can voice chat with others
- #bikeshedding: a Discord channel that is great for chatting about anything really

### Getting Help

If you need help (technical/non-technical), we suggest following this approach:
1. Ask you group members. If they don't know, chances are they'll be able to tell you where to look/post.
2. Post in the #reason-dojo channel 
3. If it should be brought up privately, you can DM Joe(@jsjoeio) or Sean(@sgrove)

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

3. Type the username of the friends that you want to add to your group (please include the moderators as well -- jsjoeio#7954 and sgrove#7438)

![screenshot showing where to type the names of your group members.](images/group-dm-discord-type-name.png)

4. Click "Create Group DM" 

![screenshot showing the button to click to create a group dm on Discord](images/create-group-dm-button.png)

## FAQ

### How will teams be divided up?

Ideally, each group will have 3 or more members. We will divide teams up evenly based on the number of attendees. Each group will have at least one experienced Reason developer. The least experienced person will drive while the others coach, mentor and guide. Everyone will work as a team.

When it comes time to split up team members, here's what will happen:
1. One of the moderators will let you know that it's time for team formation
2. They will post on the #reason-dojo asking each person to react to the message with an emoji based on their experience (legend will be provided). Here's an example:
```markdown
EXPERIENCE POLL MESSAGE TEMPLATE
---
To divide up the groups evenly, please identify your experience level based on the following:
1️⃣= "I'm new to Reason/I tried it online, but never set up a project for it"
2️⃣= "I've set up a small side project"
3️⃣= "I've published a project written in Reason"
4️⃣= "I work full time in Reason"
```
3. After all attendees respond, the moderator will post a second message with the groups.
```markdown
GROUP ANNOUNCMENT MESSAGE TEMPLATE
---
Here are the groups:

Group 1 - @name 
Group 2 -
Group 3 - 
Group 4 - 
Group 5 - 

The first name listed for each group should be the one in charge of starting the Group DM. Please refer to the repo if you need instructions on how to do that. 

Please make sure to add both of the moderators to your group as well. This will allow us to check-in and help as needed.
Mods:
- jsjoeio#7954
- sgrove#7438 

Link: <https://github.com/ReasonDojo/reason-dojo-may-2020#creating-a-group-dm-on-discord>
```
4. Group DMs will be created by the first person listed in the group.

### How am I going to shared an editor or my IDE with my group memebers?

We recommend using [Live Share](https://marketplace.visualstudio.com/items?itemName=MS-vsliveshare.vsliveshare). It's a VS Code extension that allows you to pair/mob-program with other members. If you get stuck or need help, post in the #reason-dojo channel and we'll assit you.

### How am I going to chat with my group members?

You can start a video or audio call in the Group DM. You should see an option in the top right part of the UI.

### How will the moderators be able to check-in with each group?

When you create the Group DM, make sure to add both of the moderators -- jsjoeio#7954 and sgrove#7438 -- this way, we can check in with you all and help when needed. 

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
