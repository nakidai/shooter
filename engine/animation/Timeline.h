//
// Created by Иван Ильин on 03.10.2021.
//

#ifndef SHOOTER_TIMELINE_H
#define SHOOTER_TIMELINE_H
#include <memory>

#include "Animation.h"

class AnimationListTag final {
private:
    const std::string _name;
public:
    explicit AnimationListTag(std::string name = "") : _name(std::move(name)) {}

    [[nodiscard]] std::string str() const { return _name; }

    bool operator==(const AnimationListTag &tag) const { return _name == tag._name; }

    bool operator!=(const AnimationListTag &tag) const { return _name != tag._name; }

    bool operator<(const AnimationListTag &tag) const { return _name < tag._name; }
};

class Timeline {
private:
    std::map<AnimationListTag, std::list<std::shared_ptr<Animation>>> _animations;

    static Timeline *_instance;
    static bool _validInstance;

    Timeline() = default;

public:
    Timeline(const Timeline &) = delete;

    Timeline &operator=(Timeline &) = delete;

    static void update();

    static void animate(const AnimationListTag &listName, std::shared_ptr<Animation> anim);

    static void deleteAllAnimations();

    static void deleteAnimationList(const AnimationListTag &listName);

    [[nodiscard]] static bool isInAnimList(const AnimationListTag &listName);

    static void init();

    static void free();
};

#endif //SHOOTER_TIMELINE_H
