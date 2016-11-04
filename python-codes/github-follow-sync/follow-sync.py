#!/usr/bin/env python
# coding: utf-8

# GitHub
# Follow我的, Follow之
# 未Follow我的，从Following中删除之
# 即同步互Follow关系

import  getpass
from github import Github
from github import PaginatedList
from github import NamedUser

# 始终Follow
ALWAYS_FOLLOW = [
    'torvalds',
    'jiangdon2007',
    'michaelliao',
    'zcbenz',
    'ruanyf',
]


def sync():
    username = raw_input('Username:')
    password = getpass.getpass()
    print 'Please wait...'

    g = Github(username, password)
    me = g.get_user()
    followers = me.get_followers()
    following = me.get_following()

    followers_names = [x.login for x in followers]
    following_names = [x.login for x in following]

    all_is_ok = True

    for user in following_names:
        is_my_follower = user in followers_names
        in_always_list = user in ALWAYS_FOLLOW
        if (not is_my_follower) and (not in_always_list):
            me.remove_from_following(g.get_user(user))
            print 'User \'%s\' has been removed from following list!' % user
            all_is_ok = False

    for user in followers_names:
        if user not in following_names:
            me.add_to_following(g.get_user(user))
            print 'New user \'%s\' has been followed!' % user
            all_is_ok = False

    if all_is_ok:
        print 'All is OK!'

if __name__ == "__main__":
    sync()

