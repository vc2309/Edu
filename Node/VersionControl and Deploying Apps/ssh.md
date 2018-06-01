#SSH Keys

## Command
`ssh-keygen -t rsa -b 4096 -C 'vishnu.chopra2309@gmail.com'`
- This will generate a `id_rsa` file which is the private key which must only be kept locally, and the `id_rsa.pub` file which can be shared with websites like heroku.

## Startup the SSH agent
`eval "$(ssh-agent -s)"`
- This will return an Agent pid
- Now tell the ssh agent where the private key file is
`ssh-add ~/.ssh/id_rsa`
- Add to github.com
https://help.github.com/articles/adding-a-new-ssh-key-to-your-github-account/